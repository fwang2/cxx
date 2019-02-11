#include <boost/program_options.hpp>

namespace po = boost::program_options;
namespace postyle = boost::program_options::command_line_style;


int main(int argc, char**argv) {

    po::options_description desc("Options");

    desc.add_options()
        ("mount_path", po::value<std::string>(&ufs_data.mount_path)->required(), "mount path")
        ("config", po::value<std::string>(&ufs_data.config_file)->required(),"config file")
        ("help,h", "Print this help message");

    // handle positional parameters
    po::positional_options_description posOpts;
    posOpts.add("mount_path",1); // we expect only one arg

    int unix_style = postyle::unix_style | postyle::short_allow_next;

    po::variables_map vm;

    try {
        po::store(po::command_line_parser(argc, argv)
            .options(desc)
            .positional(posOpts)
            .style(unix_style)
            .run(), vm);

        po::notify(vm);

        if (argc == 1 || vm.count("help")) {
            std::cout << "Usage: " << argv[0] << "\n" << desc << "\n";
            return 0;
        }
    } catch (po::error &poe) {
        std::cerr << poe.what() << "\n"
            << "Usage: " << argv[0] << "\n" << desc << "\n";
        return EXIT_FAILURE;
    }
}

