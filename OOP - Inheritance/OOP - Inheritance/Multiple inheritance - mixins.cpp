#include <string>

struct Point2D
{
	int x;
	int y;
};

class Box    //mixin Box class
{
public:
	void setTopLeft(Point2D point) { m_topLeft = point; }
	void setBottomRight(Point2D point) { m_bottomRight = point; }

private:
	Point2D m_topLeft{};
	Point2D m_bottomRight{};
};

class Label   //mixin Label class
{
public:
	void setText(const std::string_view str) { m_text = str; }
	void setFontSize(int fontSize) { m_fontSize = fontSize; }

private:
	std::string m_text{};
	int m_fontSize{};
};

class Button: public Box, public Label{};

int main()
{
	Button button{};
	button.Box::setTopLeft( {1,1}) ;
	button.Box::setBottomRight({ 10,10 });
	button.Label::setText("Username: ");
	button.Label::setFontSize(6);



	return 0;
}
