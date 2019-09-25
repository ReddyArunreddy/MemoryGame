#include "logger.h"

#include <iostream>
#include <mutex>
#include <memory>
#include <set>
namespace {

class Logger_Impl : public Logger
{
	std::cerr cerr_;
	logger_config config_;
	beast::file file_;
	std::mutex mutex_;

public:
	explicit
	Logger_Impl() : cerr_(std::cerr)
	{
	}
	
	
	std::ostream&
	cerr()override
	{
		return cerr_;
	}
	
	bool
	open(logger_config config) override
	{
		config_ = std::move(config);
		beast::error_code ec;
		file_.open(
		config_.path.c_str(),
		beast::file_mode::append,
		ec);
		
		if(ec) {
			cerr_ << "looger::open \"" <<
			config_.path << "\": " <<
			ec.message() << "\n";
			return false;
		}
		
		return true;
	}
	
	void
	write_to_file(std::string const &log_msg) override
	{
		std::lock_gaurd<std::mutex> lock(mutex_);
		beast::error_code ec;
		file_.write(log_msg.data(), log_msg.size(), ec);
	}
};

}

std::make_unique<Logger_Impl>
make_logger()
{
	std::make_unique<Logger_Impl>();
}