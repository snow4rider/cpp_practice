#include <cstdio>

struct ConsoleLogger
{
  /// @brief Log a transfer operation to the console.
  ///
  /// @param from The source account of the transfer.
  /// @param to The target account of the transfer.
  /// @param amount The amount of money transferred.
  void
  log_transfer (long from, long to, double amount)
  {
    printf ("%ld -> %ld: %f\n", from, to, amount);
  }
};

struct Bank
{
  /// @brief Perform a transfer between two accounts and log the operation.
  ///
  /// @param from The source account of the transfer.
  /// @param to The target account of the transfer.
  /// @param amount The amount of money transferred.
  void
  make_transfer (long from, long to, double amount)
  {
    logger.log_transfer (from, to, amount);
  }
  ConsoleLogger logger;
};

/// @brief Main entry point of the program.
///
/// This function creates a Bank object and performs two transfer operations
/// between accounts, logging each transfer to the console.
int
main ()
{
  Bank bank;
  bank.make_transfer (1000, 2000, 49.95);
  bank.make_transfer (2000, 4000, 20.00);
}
