//  this example shows how to have
//  code like the one in GroovyBuilder_test 
//
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

struct Tag
  {
    std::string name;
    std::string text;
    std::vector<Tag> children;
    std::vector<std::pair<std::string, std::string>> attributes;

    friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
    {
      os << "<" << tag.name;

      for (const auto& att : tag.attributes)
        os << " " << att.first << "=\"" << att.second << "\"";

      if (tag.children.size() == 0 && tag.text.length() == 0)
      {
        os << "/>" << std::endl;
      } 
      else
      {
        os << ">" << std::endl;

        if (tag.text.length())
          os << tag.text << std::endl;

        for (const auto& child : tag.children)
          os << child;

        os << "</" << tag.name << ">" << std::endl;
      }

      return os;
    }
  protected:

    Tag(const std::string& name, const std::string& text)
    {
		this->name = name;
		this->text = text;

    }


    Tag(const std::string& name, const std::vector<Tag>& children)
    {
		this->name = name;
		this->children = children;
    }
  };


struct P :Tag
{
	explicit P(const std::string text)
		:Tag{ "P", text }
	{
	}

	explicit P (std::initializer_list<Tag> childrens)
		:Tag{ "P",  childrens}
	{
		
	}
};

struct IMG :Tag
{
	explicit IMG(const std::string url)
		:Tag("img", "")
	{
		attributes.emplace_back(std::make_pair("src", url));
	}
};

int GroovyBuilder_test()
{

	std::cout <<
	P {
		IMG{ "http://assets.pokemon.com/assets/cms2/img/pokedex/full/004.png" }, 
		P{"Hello"}
	}
	<< std::endl;

	return 0;
}