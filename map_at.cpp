#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,int> mymap = {
                { "Mars", 3000},
                { "Saturn", 60000},
                { "Jupiter", 70000 } };

  mymap.at("Mars") = 3396;
  mymap.at("Saturn") += 272;
  mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }

  try
  {
    mymap.at("Earth");
  }
  catch (...)
  {
    std::cout << "exception" << std::endl;
  }

  return 0;
}