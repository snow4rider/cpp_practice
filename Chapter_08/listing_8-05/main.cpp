#include <cstdio>

namespace BroopKipron13::Shaltanc {
  enum class Color {
    Mauve, Pink, Russet
  };
}

int main() {
  const auto shaltanac_grass{ BroopKipron13::Shaltanc::Color::Russet };
  if(shaltanac_grass == BroopKipron13::Shaltanc::Color::Russet){
    printf("The other Shaltanc's joopleberry shrub is always "
        "a more mauvey shade of pinky russet.");
  }
}
