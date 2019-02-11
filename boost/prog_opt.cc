
int main(int argc, char**argv) {

    std::string config_file;
    po::options_description desc("Options");
    desc.add_options()
        ("config", po::value<std::string>(&config_file)->required(),"config file")
        ("help,h", "Print this help message");

    int unix_style = postyle::unix_style|postyle::short_allow_next;

    po::variables_map vm;

    try {
        po::store(po::command_line_parser(argc, argv)
            .options(desc)
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
