// Open for extension closed for modification principle
// instead of using a filter class that we modify each time
// we want to filter by field we use specification pattern
// to extend functionality

#include <string>
#include <vector>
#include <iostream>

enum class Color {Red, Blue, Green };
enum class Size {Small, Medium, Big};

struct Product
{
	std::string name;
	Color       color;
	Size        size;
};

template <typename T>
struct ISpecification
{
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct IFilter
{
	virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};


struct Filter : IFilter <Product>
{
	typedef std::vector<Product* > Items;
	std::vector<Product* > filter(std::vector<Product*> items, ISpecification<Product>& spec)
	{
		Items results;
		for (auto& p : items)
		{
			if (spec.is_satisfied(p))
				results.push_back(p);
		}
		return results;
	}
};

struct ColorSpecification : ISpecification < Product >
{
	explicit ColorSpecification(Color c)
		:color{ c }
	{}

	bool is_satisfied (Product *p) override {
		return color == p->color;
	}

private:
	Color color;
};

int main()
{
	Product Apple{ "Apple", Color::Green, Size::Small };
	Product Tree{ "Tree", Color::Green, Size::Big };
	Product House{ "House", Color::Blue, Size::Medium };

	std::vector < Product * > items {&Apple, &Tree, &House};
	Filter flt;
	ColorSpecification green(Color::Green);

	auto result = flt.filter(items, green);
	for (auto& r : result)
		std::cout << r->name << std::endl;

	getchar();
	return 0;
}

