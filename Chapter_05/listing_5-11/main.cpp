#include <cstdio>

struct Logger
{
  virtual ~Logger () = default;
  virtual void log_transfer (long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger
{
  /// @brief Log a transfer operation to the console.
  ///
  /// @param from The source account of the transfer.
  /// @param to The target account of the transfer.
  /// @param amount The amount of money transferred.
  void
  log_transfer (long from, long to, double amount) override
  {
    printf ("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct FileLogger : Logger
{
  /// @brief Log a transfer operation to a file.
  ///
  /// @param from The source account of the transfer.
  /// @param to The target account of the transfer.
  /// @param amount The amount of money transferred.
  void
  log_transfer (long from, long to, double amount) override
  {
    printf ("[file] %ld,%ld,%f\n", from, to, amount);
  }
};

struct Bank
{
  Bank (Logger &logger) : logger{ logger } {}

  /// @brief Perform a transfer between two accounts and log the operation.
  ///
  /// @param from The source account of the transfer.
  /// @param to The target account of the transfer.
  /// @param amount The amount of money transferred.
  void
  make_transfer (long from, long to, double amount)
  {
    //
    logger.log_transfer (from, to, amount);
  }

private:
  Logger &logger;
};

/// @brief Main entry point of the program.
///
/// This function creates a ConsoleLogger object and passes it to the Bank
/// constructor. It then performs two transfer operations between accounts,
/// logging each transfer to the console.
int
main ()
{
  ConsoleLogger logger;
  Bank bank{ logger };
  bank.make_transfer (1000, 2000, 49.95);
  bank.make_transfer (2000, 4000, 20.00);
}