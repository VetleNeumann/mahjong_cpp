#pragma once
#include "tile.hpp"
#include <stdexcept>
#include <vector>

namespace Mahjong {
class Wall
{
public:
  constexpr Mahjong::Tile drawTile();
  constexpr Mahjong::Tile drawFromDeadWall();

  [[nodiscard]] constexpr std::vector<Mahjong::Tile> getDoraIndicators() const;
  constexpr std::vector<Mahjong::Tile> revealNewDoraIndicator();

private:
  std::vector<Mahjong::Tile> m_Wall;
  std::vector<Mahjong::Tile> m_DeadWall;
  // make wall
  // get:
  //  - next tile
  //  - tile from dead wall
  // keep track of dead wall as well
  // keep track of dora indicators
  // be able to
};
}// namespace Mahjong

constexpr Mahjong::Tile Mahjong::Wall::drawTile()
{
  const Mahjong::Tile drawnTile = m_Wall.front();
  m_Wall.erase(m_Wall.begin());
  return drawnTile;
}

constexpr Mahjong::Tile Mahjong::Wall::drawFromDeadWall() { return m_DeadWall.back(); }
