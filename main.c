#include "push_swap.h"
#include <stdio.h>
int ft_atoi(const char *str) {
  int i = 0;
  int sign = 1;
  long result = 0;

  while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    i++;
  if (str[i] == '-' || str[i] == '+') {
    if (str[i] == '-')
      sign = -1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    result = result * 10 + (str[i] - '0');
    if (result * sign > 2147483647)
      return (-1);
    if (result * sign < -2147483648)
      return (0);
    i++;
  }
  return ((int)(result * sign));
}

void ft_stack_print(t_node *head) {
  while (head != NULL) {
    printf("%d -> ", head->value);
    head = head->next;
  }
  printf("NULL\n");
}

int main(int argc, char **argv) {
  if (argc < 2)
    return (0);
  int i = 1;
  int j = 0;
  while (argv[i] && argv[i][j]) {
    if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' &&
        argv[i][j] != '+' && argv[i][j] != ' ') {
      write(2, "Error\n", 6);
      return (1);
    }
    j++;
    if (argv[i][j] == '\0') {
      i++;
      j = 0;
    }
  }
  i = 1;
  // j = 0;
  while (argv[i]) {
    node_new(ft_atoi(argv[i]));
    i++;
  }
}