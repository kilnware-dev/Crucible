

#include "connection/init.hpp"
#include "core/diagnostic.hpp"
#include "connection/client.hpp"

#include <CLI/CLI.hpp>

#include <filesystem>
#include <print>
#include <string>
#include <string_view>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
	CLI::App app{ "Crucible" };
	app.require_subcommand(1);

	std::string target_name = "Foo";

	auto* init_cmd = app.add_subcommand("init", "Initialize target and start auto-building daemon");
	init_cmd->add_option("Target", target_name, "The target name. The appropiate <target>.yaml will be loaded.")
		->required();
	init_cmd->callback([&] { init(target_name});


	CLI11_PARSE(app, argc, argv);
	return 0;
}

// crucible

