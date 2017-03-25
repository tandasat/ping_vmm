// ping_vmm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void IsVmmInstalled() {
  static const unsigned long kHyperVCpuidInterface = 0x40000001;

  // Issue CPUID with the back-door code. "HypP" should be returned in EAX if
  // HyperPlatform is installed.
  int cpu_info[4] = {};
  __cpuidex(cpu_info, kHyperVCpuidInterface, 0);

  char vendor_id[5] = {};
  memcpy(&vendor_id[0], &cpu_info[0], 4);  // eax
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
