#include "Mahjong/tile.hpp"
#include <catch2/catch.hpp>
#include <map>

using namespace Mahjong;

TEST_CASE("Tiles to string, all suits", "[tile]")
{
  auto tiles = { Tile{ Suit::Souzu, Value::Kyuu, false },
    Tile{ Suit::Manzu, Value::Ii, false },
    Tile{ Suit::Pinzu, Value::Chii, false },
    Tile{ Suit::Honor, Value::Hatsu, false },
    Tile{ Suit::Honor, Value::Pei, false },
    Tile{ Suit::Manzu, Value::Suu, false },
    Tile{ Suit::Manzu, Value::Uu, true },
    Tile{ Suit::Manzu, Value::Uu, false },
    Tile{ Suit::Honor, Value::Nan, false },
    Tile{ Suit::Honor, Value::Shaa, false },
    Tile{ Suit::Honor, Value::Ton, false },
    Tile{ Suit::Honor, Value::Haku, false },
    Tile{ Suit::Honor, Value::Chun, false } };
  REQUIRE(tilesToString(tiles) == "1450m7p9s1234567z");
}

TEST_CASE("Tiles to string, suits missing", "[tile]")
{
  auto tiles = { Tile{ Suit::Pinzu, Value::Kyuu, false },
    Tile{ Suit::Pinzu, Value::Ii, false },
    Tile{ Suit::Pinzu, Value::Chii, false },
    Tile{ Suit::Honor, Value::Hatsu, false },
    Tile{ Suit::Honor, Value::Pei, false } };
  REQUIRE(tilesToString(tiles) == "179p46z");
}