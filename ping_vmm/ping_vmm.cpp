// ping_vmm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void IsVmmInstalled() {
  int cpu_info[4] = {};
  __cpuidex(cpu_info, 0, 'gniP');
  char vendor_id[13] = {};
  memcpy(&vendor_id[0], &cpu_info[1], 4);   // ebx
  memcpy(&vendor_id[4], &cpu_info[3], 4);   // edx
  memcpy(&vendor_id[8], &cpu_info[2], 4);   // ecx
  std::cout << "Ping : " << vendor_id << std::endl;
}

int main() {
  using namespace std::literals;

  for (;;) {
    IsVmmInstalled();
    std::this_thread::sleep_for(2s);
  }
  return 0;
}
