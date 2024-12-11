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
  /// @brief Set the logger used by the bank.
  ///
  /// @param new_logger The new logger to use. If @p nullptr, the bank will
  /// not log any operations.
  void
  set_logger (Logger *new_logger)
  {
    logger = new_logger;
  }

  /// @brief Perform a transfer between two accounts and log the operation.
  ///
  /// @param from The source account of the transfer.
  /// @param to The target account of the transfer.
  /// @param amount The amount of money transferred.
  ///
  /// If the Bank object has a logger set (i.e., the logger is not a null
  /// pointer), the transfer operation will be logged. Otherwise, no log
  /// operation will be performed.
  void
  make_transfer (long from, long to, double amount)
  {
    if (logger)
      logger->log_transfer (from, to, amount);
  }

private:
  Logger *logger{};
};

/// @brief Main entry point of the program.
///
/// This function creates ConsoleLogger and FileLogger objects and uses them
/// to log transfer operations in a Bank object. It first sets the logger to
/// ConsoleLogger and performs a transfer, then switches to FileLogger and
/// performs another transfer.
int
main ()
{
  ConsoleLogger console_logger;
  FileLogger file_logger;
  Bank bank;
  bank.set_logger (&console_logger);
  bank.make_transfer (1000, 2000, 49.95);
  bank.set_logger (&file_logger);
  bank.make_transfer (2000, 4000, 20.00);
}