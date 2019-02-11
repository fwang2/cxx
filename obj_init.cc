class X {
private:
  int m_x;
  int m_y;

public:
  X(double x = 0, double y = 0) {
    m_x = x;
    m_y = y;
  }
};

int main() {
  X obj;

  return 0;
}