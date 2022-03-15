#include <algorithm>
#include <functional>
#include <iostream>

#include <docopt/docopt.h>
#include <spdlog/spdlog.h>

#include "Mahjong/wall.hpp"

// This file will be generated automatically when you run the CMake configuration step.
// It creates a namespace called `myproject`.
// You can modify the source template at `configured_files/config.hpp.in`.
#include <configured_files/config.hpp>

// static constexpr auto USAGE =
//   R"(Naval Fate.
//
//     Usage:
//           naval_fate ship new <name>...
//           naval_fate ship <name> move <x> <y> [--speed=<kn>]
//           naval_fate ship shoot <x> <y>
//           naval_fate mine (set|remove) <x> <y> [--moored | --drifting]
//           naval_fate (-h | --help)
//           naval_fate --version
//  Options:
//           -h --help     Show this screen.
//           --version     Show version.
//           --speed=<kn>  Speed in knots [default: 10].
//           --moored      Moored (anchored) mine.
//           --drifting    Drifting mine.
//)";

int main([[maybe_unused]] int argc, [[maybe_unused]] const char **argv)
{
  return 0;

  // try {
  //   std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
  //     { std::next(argv), std::next(argv, argc) },
  //     true,// show help if requested
  //     fmt::format("{} {}",
  //       myproject::cmake::project_name,
  //       myproject::cmake::project_version));// version string, acquired from config.hpp via CMake

  //  for (auto const &arg : args) { std::cout << arg.first << "=" << arg.second << '\n'; }


  //  // Use the default logger (stdout, multi-threaded, colored)
  //  spdlog::info("Hello, {}!", "World");

  //  fmt::print("Hello, from {}\n", "{fmt}");
  //} catch (const std::exception &e) {
  //  fmt::print("Unhandled exception in main: {}", e.what());
  //}
}
