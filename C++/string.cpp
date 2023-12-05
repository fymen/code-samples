import <iostream>;
import <string>;
import <vector>;
import <regex>;

// using namespace std;

int print(int& n)
{
  n = n * 100;

  return 0;
}
int main(int argc, char **argv)
{
  auto nth_fibonacci = [](int n)
  {
    std::function<int(int, int, int)> fib = [&](int n, int a, int b){
      return n ? fib(n-1, a+b, a) : b;
    };
    return fib(n, 0, 1);
  };

  std::cout << nth_fibonacci(10) << std::endl;

  return 0;
}
