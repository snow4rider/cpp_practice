#include <cstdint>

struct PodStruct
{
  uint64_t a;
  char b[256];
  bool c;
};

// Demonstrates different ways to initialize a POD (Plain Old Data) struct.
// - initialized_pod1: Default initialization with all fields zeroed.
// - initialized_pod2: Default initialization with all fields zeroed using
// assignment.
// - initialized_pod3: Initializes fields a and b, field c is set to false
// (zero).
// - initialized_pod4: Initializes all fields with specified values.
int
main ()
{
  PodStruct initialized_pod1{};    // All fields zeroed
  PodStruct initialized_pod2 = {}; // All fields zeroed

  PodStruct initialized_pod3{ 42, "Hello" };       // Fields a & b set; c = 0
  PodStruct initialized_pod4{ 42, "Hello", true }; // All fields set
}
