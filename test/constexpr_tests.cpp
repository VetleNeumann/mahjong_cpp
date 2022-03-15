#include "Mahjong/tile.hpp"
#include <algorithm>
#include <catch2/catch.hpp>
#include <map>
using namespace Mahjong;

TEST_CASE("Set generated properly", "[tile]")
{
  auto set = Mahjong::generateTileSet(true);
  REQUIRE(set.size() == 136);

  auto tileCount = std::map<Tile, uint8_t>{};
  for (const auto &tile : set) {
    const auto tileIterator = tileCount.find(tile);
    if (tileIterator == std::end(tileCount)) { tileCount.insert({ tile, 0 }); }
    ++tileCount[tile];
  }
  const auto tilesWithoutExactly4Tiles = std::ranges::count_if(
    tileCount, [&](const auto &tileCountEntry) constexpr { return tileCountEntry.second != 4; });
  REQUIRE(tilesWithoutExactly4Tiles == 6);// Each suit has fives and a red five, which there aren't 4 of

  const auto redTileCount = std::ranges::count_if(
    set, [&](const Tile &tile) constexpr { return tile.red; });
  REQUIRE(redTileCount == 3);
}

TEST_CASE("Tile suit comparison", "[tile]")
{
  // Manzu < Pinzu < Souzu
  const auto manzuTile = Tile{ Suit::Manzu, Value::Ii, false };
  const auto pinzuTile = Tile{ Suit::Pinzu, Value::Ii, false };
  const auto souzuTile = Tile{ Suit::Souzu, Value::Ii, false };
  REQUIRE(manzuTile < pinzuTile);
  REQUIRE(pinzuTile < souzuTile);
  REQUIRE(manzuTile < souzuTile);
  REQUIRE((manzuTile < manzuTile) == false);
}

TEST_CASE("Tile value comparison", "[tile]")
{
  // 1 < 2
  const auto manzuIiTile = Tile{ Suit::Manzu, Value::Ii, false };
  const auto manzuRyanTile = Tile{ Suit::Manzu, Value::Ryan, false };
  REQUIRE(manzuIiTile < manzuRyanTile);
  REQUIRE(manzuRyanTile > manzuIiTile);
}

TEST_CASE("Tile equality comparison", "[tile]")
{
  // ==
  const auto manzuTile = Tile{ Suit::Manzu, Value::Ii, false };
  const auto souzuTile = Tile{ Suit::Souzu, Value::Ii, false };
  const auto sameManzuTile = manzuTile;
  REQUIRE(manzuTile == sameManzuTile);
  REQUIRE(manzuTile != souzuTile);
}

TEST_CASE("Tile red comparison", "[tile]")
{
  // Red > Not red
  const auto redManzuTile = Tile{ Suit::Manzu, Value::Ii, true };
  const auto manzuTile = Tile{ Suit::Manzu, Value::Ii, false };
  REQUIRE(redManzuTile > manzuTile);
  REQUIRE(manzuTile < redManzuTile);
}