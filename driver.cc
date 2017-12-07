#include "driver.hh"

calcxx_driver::calcxx_driver ()
  : trace_scanning (false), trace_parsing (false){}

calcxx_driver::~calcxx_driver ()
{
}

int
calcxx_driver::parse (const std::string &f)
{
  file = f;
  scan_begin ();

  yy::calcxx_parser parser (*this);
  parser.set_debug_level (trace_parsing);
  int res = parser.parse ();
  scan_end ();


  print_visitor p = print_visitor();
  p.visit_ast(this -> result);

  resolve_scope s = resolve_scope();
  s.visit_ast(this -> result);

  return res;
}

void
calcxx_driver::error (const yy::location& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

void
calcxx_driver::error (const std::string& m)
{
  std::cerr << m << std::endl;
}
