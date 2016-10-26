#include <string>
#include <iostream>

#include <boost/program_options.hpp>

#ifndef OPTIONS_H_
#define OPTIONS_H_

namespace po = boost::program_options;

class Options
{
	public:
		static const Options & get(int argc = 0, char ** argv = 0)
		{
			static const Options instance(argc, argv);

			return instance;
		}

		std::string logfile;
		int fps;
		int width;
		int height;
		int compressed;

		private:
			Options(int argc, char ** argv)
			:width(640),
			height(480),
			fps(30),
			compressed(0)
			{
				po::options_description desc("LogViewer, A tool for playing back (dot)klg files.\n Options");
				
				desc.add_options()
					("help,h", "print help message")
					("logfile,l", po::value<std::string>(), "log to play back");

				po::variables_map vm;
				po::store(po::parse_command_line(argc, argv, desc), vm);
				po::notify(vm);

				if(vm.count("help"))
				{
					std::cout << desc << "\n";
					std::exit(EXIT_SUCCESS); 
				}

				if(vm.count("logfile"))
					logfile = vm["logfile"].as<std::string>();

			}
};

#endif // OPTIONS_H_