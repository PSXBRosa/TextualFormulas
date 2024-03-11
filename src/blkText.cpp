#include "blkText.hpp"

blk::expr blk::text(std::string label){
  return std::make_shared<blk::Text>(label, 0);
}

blk::expr blk::text(std::string label, int pos){
  return std::make_shared<blk::Text>(label, pos);
}

blk::Text::Text(std::string label, int pos):
  Block(label.size(), 1, compute_rel_width(label, pos), 0),
  label(label), pos(pos) {}

void blk::Text::print_inbounds_line(std::ostream& os, int line) const{
  os << label;
}
