#pragma once

#include <iostream>
#include <memory>


namespace blk {

  class Block;
  using expr = std::shared_ptr<const Block>;

  std::ostream& operator<<(std::ostream& os, expr e);

  class Block {
  private:

    int width;
    int height;
    int ref_width;
    int ref_height;

    // Returns the lowest line number which is in the block.
    int min_line() const;

    // Returns 1 + the highest line number which is in the block.
    int max_line() const;

  public:
    // Prints any line. If the line is outside the block, it prints a
    // range of spaces. Otherwise, it calls print_inbounds_line to
    // print the block content at that line.
    void print_line(std::ostream& os, int line) const;

  private:

    // This will call the private min_line and max_line methods.
    friend std::ostream& operator<<(std::ostream& os, expr block);

  public:

    Block(int width,
	  int height,
	  int ref_width,
	  int ref_height);
    virtual ~Block() {}

    // This prints the line numbered line, if line is in [min_line(),
    // max_line()[.
    virtual void print_inbounds_line(std::ostream& os, int line) const = 0;

    int get_width()      const;
    int get_height()     const;
    int get_ref_width()  const;
    int get_ref_height() const;
  };
}
