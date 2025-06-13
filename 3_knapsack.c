#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);
  
  float w[n], p[n];
  float capacity;
  printf("Enter capacity: ");
  scanf("%f", &capacity);
  
  // Data input:
  for (int i = 0; i < n; i++) {
    printf("Enter the weight and profit of the item %d respectively:\n", i + 1);
    scanf("%f%f", &w[i], &p[i]);
  }

  // Printing the array:
  printf("The weight and profit entered are:\nWEIGHT: ");
  for (int i = 0; i < n; i++) {
    printf("%.2f  ", w[i]);
  }
  printf("\nPROFIT: ");
  for (int i = 0; i < n; i++) {
    printf("%.2f ", p[i]);
  }
  printf("\n");

  // Calculating ratio and sorting
  float ratio[n];
  printf("RATIO : ");
  for (int i = 0; i < n; i++) {
    ratio[i] = p[i] / w[i];
    printf("%.2f ", ratio[i]);
  }
  printf("\n");

  // Sorting:
  for (int i = 0; i < n - 1; i++) {
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (ratio[j] > ratio[max]) {
        max = j;
      }
    }
    // Sorting profit
    float temp = p[i];
    p[i] = p[max];
    p[max] = temp;

    // Sorting weight
    temp = w[i];
    w[i] = w[max];
    w[max] = temp;

    // Sorting ratio
    temp = ratio[i];
    ratio[i] = ratio[max];
    ratio[max] = temp;
  }

  printf("RATIO : ");
  for (int i = 0; i < n; i++) {
    printf("%.2f ", ratio[i]);
  }
  printf("\n");

  // Knapsack or profit calculation:
  float max_profit = 0.0;
  for (int i = 0; i < n; i++) {
    if (capacity >= w[i]) {
      max_profit += p[i];
      capacity -= w[i];
    } else {
      max_profit += (p[i] * (capacity / w[i]));
      capacity = 0;
      break;
    }
  }

  printf("Maximum profit: %f", max_profit);

  return 0;
}
