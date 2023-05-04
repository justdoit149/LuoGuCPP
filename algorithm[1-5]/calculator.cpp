//高精度计算器


#include <cstdio>
#include <cstring>

static const int LEN = 1004;

int a[LEN], b[LEN], c[LEN], d[LEN];

void clear(int a[]) {
  for (int i = 0; i < LEN; ++i) a[i] = 0;
}

//由于传进来的数组实际上是个指针，因此是可修改的；而传进来变量是值传递，不可修改
void read(int a[]) {//读取高精度数据，并把它存到传进来的数组里，最前面是最低位
  static char s[LEN + 1];
  scanf("%s", s);
  clear(a);
  int len = strlen(s);
  for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
}

void print(int a[]) {//输出某个数组存储的高精度数据
  int i;
  for (i = LEN - 1; i >= 1; --i) if (a[i] != 0) break;
  for (; i >= 0; --i) putchar(a[i] + '0');
  putchar('\n');
}

void add(int a[], int b[], int c[]) {//实现加法，c[i]数组存结果
  clear(c);
  for (int i = 0; i < LEN - 1; ++i) {
    c[i] += a[i] + b[i];
    if (c[i] >= 10) {
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}

void sub(int a[], int b[], int c[]) {//实现减法
  clear(c);
  for (int i = 0; i < LEN - 1; ++i) {
    c[i] += a[i] - b[i];
    if (c[i] < 0) {
      c[i + 1] -= 1;
      c[i] += 10;
    }
  }
}

void mul(int a[], int b[], int c[]) {//实现乘法
  clear(c);
  for (int i = 0; i < LEN - 1; ++i) {
    for (int j = 0; j <= i; ++j) c[i] += a[j] * b[i - j];
  // 将所有的结果保留在对应的位置上，到最后再统一处理进位
    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}

inline bool greater_eq(int a[], int b[], int last_dg, int len) {
  if (a[last_dg + len] != 0) return true;
  for (int i = len - 1; i >= 0; --i) {
    if (a[last_dg + i] > b[i]) return true;
    if (a[last_dg + i] < b[i]) return false;
  }
  return true;
}

void div(int a[], int b[], int c[], int d[]) {
  clear(c);
  clear(d);
  int la, lb;
  for (la = LEN - 1; la > 0; --la)
    if (a[la - 1] != 0) break;
  for (lb = LEN - 1; lb > 0; --lb)
    if (b[lb - 1] != 0) break;
  if (lb == 0) {
    puts("> <");
    return;
  }
  for (int i = 0; i < la; ++i) d[i] = a[i];
  for (int i = la - lb; i >= 0; --i) {
    while (greater_eq(d, b, i, lb)) {
      for (int j = 0; j < lb; ++j) {
        d[i + j] -= b[j];
        if (d[i + j] < 0) {
          d[i + j + 1] -= 1;
          d[i + j] += 10;
        }
      }
      c[i] += 1;
    }
  }
}

int main() {
  read(a);

  char op[4];
  scanf("%s", op);

  read(b);

  switch (op[0]) {
    case '+':
      add(a, b, c);
      print(c);
      break;
    case '-':
      sub(a, b, c);
      print(c);
      break;
    case '*':
      mul(a, b, c);
      print(c);
      break;
    case '/':
      div(a, b, c, d);
      print(c);
      print(d);
      break;
    default:
      puts("> <");
  }

  return 0;
}