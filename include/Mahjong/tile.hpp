#pragma once
#include <algorithm>
#include <compare>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>

namespace Mahjong {
enum class Suit : uint8_t { Manzu, Pinzu, Souzu, Honor };
enum class Value : uint8_t { Ii = 1, Ryan, San, Suu, Uu, Rou, Chii, Paa, Kyuu, Ton, Nan, Shaa, Pei, Haku, Hatsu, Chun };

struct Tile
{
  Suit suit;
  Value value;
  bool red = false;
};

[[nodiscard]] constexpr bool operator==(const Tile &lhs, const Tile &rhs) noexcept
{
  return lhs.suit == rhs.suit && lhs.value == rhs.value && lhs.red == rhs.red;
}
[[nodiscard]] constexpr bool operator!=(const Tile &lhs, const Tile &rhs) noexcept { return !(lhs == rhs); }
[[nodiscard]] constexpr bool operator<(const Tile &lhs, const Tile &rhs) noexcept
{
  if (lhs.suit != rhs.suit)
    return lhs.suit < rhs.suit;
  else if (lhs.value != rhs.value)
    return lhs.value < rhs.value;
  else if (lhs.red != rhs.red)
    return lhs.red < rhs.red;
  else
    return false;
}
[[nodiscard]] constexpr bool operator>=(const Tile &lhs, const Tile &rhs) noexcept { return !(lhs < rhs); }
[[nodiscard]] constexpr bool operator>(const Tile &lhs, const Tile &rhs) noexcept { return lhs >= rhs && lhs != rhs; }
[[nodiscard]] constexpr bool operator<=(const Tile &lhs, const Tile &rhs) noexcept { return !(lhs > rhs); }

[[nodiscard]] constexpr std::vector<Tile> generateSetOfSuitTiles(const bool redFives = false,
  const Value redValue = Value::Uu) noexcept
{
  auto set = std::vector<Mahjong::Tile>{};
  const auto ii = static_cast<uint8_t>(Value::Ii);
  const auto kyuu = static_cast<uint8_t>(Value::Kyuu);
  const auto manzu = static_cast<uint8_t>(Suit::Manzu);
  const auto souzu = static_cast<uint8_t>(Suit::Souzu);

  for (auto suit = manzu; suit <= souzu; ++suit) {
    for (auto value = ii; value <= kyuu; ++value) {
      for (auto tileCount = 0; tileCount < 4; ++tileCount) {
        const auto red = redFives && (static_cast<Value>(value) == redValue) && (tileCount == 0);
        set.push_back(Tile{ static_cast<Suit>(suit), static_cast<Value>(value), red });
      }
    }
  }
  return set;
}

[[nodiscard]] constexpr std::vector<Tile> generateSetOfHonorTiles() noexcept
{
  auto set = std::vector<Mahjong::Tile>{};
  const auto ton = static_cast<uint8_t>(Value::Ton);
  const auto chun = static_cast<uint8_t>(Value::Chun);

  for (auto value = ton; value <= chun; ++value) {
    for (auto tileCount = 0; tileCount < 4; ++tileCount) {
      set.push_back(Tile{ Suit::Honor, static_cast<Value>(value), false });
    }
  }
  return set;
}

[[nodiscard]] constexpr std::vector<Tile> generateTileSet(const bool redFives = false,
  const Value redValue = Value::Uu) noexcept
{
  auto set{ generateSetOfSuitTiles(redFives, redValue) };
  const auto honorTiles{ generateSetOfHonorTiles() };

  set.reserve(set.size() + honorTiles.size());
  set.insert(set.end(), std::make_move_iterator(honorTiles.begin()), std::make_move_iterator(honorTiles.end()));

  return set;
}

[[nodiscard]] std::string tilesToString([[maybe_unused]] std::vector<Tile> tiles)
{
  const auto suitToChar = [&](const auto &suit) constexpr
  {
    switch (suit) {
    case Suit::Manzu:
      return 'm';
    case Suit::Pinzu:
      return 'p';
    case Suit::Souzu:
      return 's';
    case Suit::Honor:
      return 'z';
    default:
      throw std::logic_error("Got unexpected suit type");
      break;
    }
  };

  std::ranges::sort(tiles);
  auto currentTileSuit = tiles.front().suit;
  auto sstream = std::ostringstream{};
  for (const auto &tile : tiles) {
    if (tile.suit != currentTileSuit) {
      sstream << suitToChar(currentTileSuit);
      currentTileSuit = tile.suit;
    }

    if (tile.red)
      sstream << '0';
    else if (tile.suit != Suit::Honor)
      sstream << std::to_string(static_cast<uint8_t>(tile.value));
    else {
      sstream << std::to_string(static_cast<uint8_t>(tile.value) - static_cast<uint8_t>(Value::Kyuu));
    }
  }
  if (currentTileSuit == Suit::Honor) sstream << 'z';

  return sstream.str();
}


}// namespace Mahjong