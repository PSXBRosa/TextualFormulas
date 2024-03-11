#include <blk.hpp>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

blk::expr applyOp(blk::expr a, blk::expr b, char op){
    switch(op){
        case '+': return a + b;
        //case '-': return a - b; TODO
        //case '*': return a * b; TODO
        case '/': return a / b;
        case '=': return a == b;
    }
}

blk::expr evaluate(std::string tokens, std::map<std::string, blk::expr> symbols){
  std::stack<blk::expr> values;
  std::stack<char> ops;

  for (int i = 0; i < tokens.length(); i++) {
    auto it = symbols.find(std::string(1, tokens[i]));

    // skip it.
    if (tokens[i] == ' ')
      continue;

    else if (tokens[i] == '(') {
      ops.push(tokens[i]);
    }

    else if (isdigit(tokens[i])) {
      int val = 0;

      // There may be more than one
      // digit in number.
      while (i < tokens.length() && isdigit(tokens[i])) {
        val = (val * 10) + (tokens[i] - '0');
        i++;
      }

      // Right now the i points to the character next to the digit.
      i--;
      values.push(blk::from_value(val));
    }

    // FIXME this only works for single char variable names
    else if (it != symbols.end()){
      values.push(it->second);
    }

    // Closing brace encountered, solve entire brace.
    else if (tokens[i] == ')') {
      while (!ops.empty() && ops.top() != '(') {
        blk::expr val2 = values.top();
        values.pop();

        blk::expr val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
      }

      // Pop opening brace.
      if (!ops.empty())
        ops.pop();
    }

    // Current token is an operator.
    else {
      while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
        blk::expr val2 = values.top();
        values.pop();

        blk::expr val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
      }

      // Push current token to 'ops'.
      ops.push(tokens[i]);
    }
  }

  // Finish evaluating the stack.
  while (!ops.empty()) {
    blk::expr val2 = values.top();
    values.pop();

    blk::expr val1 = values.top();
    values.pop();

    char op = ops.top();
    ops.pop();

    values.push(applyOp(val1, val2, op));
  }

  // Top of 'values' contains result, return it.
  return values.top();
}

int main() {
  std::map<std::string, blk::expr> symbols;
  std::cout << "ENTER AN EMPTY COMMAND TO QUIT. DEFINE VARIABLES BY PREFIXING YOUR VARIABLE NAME WITH '$'." << std::endl;

  while (true) {
    std::string line;
    std::cout << ">> ";
    std::getline(std::cin, line);
    if (line.empty()) {
      break;
    }


    if (line[0] == '$') {
      // Store symbols (variable assignments)
      std::string var_name = line.substr(1, line.length() - 1);
      symbols[var_name] = blk::text(var_name);
      continue;
    }
    // Evaluate expression
    // TODO input validation
    blk::expr result = evaluate(line, symbols);
    std::cout << "\n" << result << std::endl;
  }
  return 0;
}
