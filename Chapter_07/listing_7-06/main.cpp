#include <cstddef>
#include <cstdio>
#include <new>

struct Bucket
{
  const static size_t data_size{ 4096 };
  std::byte data[data_size];
};

struct Heap
{
  /// @brief Allocate memory from the heap.
  ///
  /// This function allocates `bytes` bytes of memory from the heap. If the
  /// allocation fails (i.e., if `bytes` is greater than the size of a single
  /// bucket), a `std::bad_alloc` exception is thrown. Otherwise, the address
  /// of the allocated memory is returned.
  void *
  allocate (size_t bytes)
  {
    if (bytes > Bucket::data_size)
      throw std::bad_alloc ();
    for (size_t i{}; i < n_heap_buckets; i++)
      {
        if (!bucket_used[i])
          {
            bucket_used[i] = true;
            return buckets[i].data;
          }
      }
    throw std::bad_alloc ();
  }

  /// @brief Free memory from the heap.
  ///
  /// This function frees the memory address `p` from the heap. If `p` is not
  /// a valid address that was previously allocated with `allocate`, the
  /// function does nothing. Otherwise, the memory is marked as available for
  /// reuse.
  void
  free (void *p)
  {
    for (size_t i{}; i < n_heap_buckets; i++)
      {
        if (buckets[i].data == p)
          {
            bucket_used[i] = false;
            return;
          }
      }
  }
  static const size_t n_heap_buckets{ 10 };
  Bucket buckets[n_heap_buckets]{};
  bool bucket_used[n_heap_buckets]{};
};

Heap heap;

/// @brief The global new operator
///
/// This function implements the global new operator. It calls `allocate` on
/// the global `heap` object to allocate the requested number of bytes, and
/// returns the pointer to the allocated memory. If the allocation fails, the
/// function throws a `std::bad_alloc` exception.
void *
operator new (size_t n_bytes)
{
  return heap.allocate (n_bytes);
}

/// @brief The global delete operator
///
/// This function implements the global delete operator. It calls `free` on the
/// global `heap` object to free the memory at the address `p`. It does not
/// check whether `p` is a valid address previously allocated with `allocate`.
void
operator delete (void *p)
{
  return heap.free (p);
}

/**
 * @brief The main entry point of the program.
 *
 * This program demonstrates the use of a custom heap implementation by
 * allocating two integers and printing their addresses and values. After
 * deleting the allocated memory, it enters a loop where it continuously tries
 * to allocate memory for a char, printing a message whenever it succeeds.
 * When the heap runs out of memory, a `std::bad_alloc` exception is caught and
 * a message is printed.
 */
int
main ()
{
  printf ("Buckets:   %p\n", heap.buckets);
  auto breakfast = new unsigned int{ 0xC0FFEE };
  auto dinner = new unsigned int{ 0xDEADBEEF };
  printf ("Breakfast: %p 0x%x\n", breakfast, *breakfast);
  printf ("Dinner:    %p 0x%x\n", dinner, *dinner);
  delete breakfast;
  delete dinner;
  try
    {
      while (true)
        {
          new char;
          printf ("Allocated a char.\n");
        }
    }
  catch (const std::bad_alloc &)
    {
      printf ("std::bad_alloc caught.\n");
    }
}