
class empty
{
	public:
	void print()
	{
		int i = 0;
	}
};

int main()
{
	empty e;
	empty b = e;
	e.print();

	return 0;
}
