void ResetISR(void) {

 // Disable interrupts

 __asm volatile ("cpsid i");

 // Disable Watchdog

 // SIM->COPC register: COPT = 0,COPCLKS = 0,COPW = 0

 *((volatile unsigned int *)0x40048100) = 0x00u;

 // Copy the data sections from flash to SRAM.

 unsigned int LoadAddr, ExeAddr, SectionLen;

 unsigned int *SectionTableAddr;

 // Load base address of Global Section Table

 SectionTableAddr = &__data_section_table;

 // Copy the data sections from flash to SRAM.

 while (SectionTableAddr < &__data_section_table_end) {

 LoadAddr = *SectionTableAddr ++;

 ExeAddr = *SectionTableAddr ++;

 SectionLen = *SectionTableAddr ++;

 data_init(LoadAddr, ExeAddr, SectionLen);

 }

 // At this point, SectionTableAddr = &__bss_section_table;

 // Zero fill the bss segment

 while (SectionTableAddr < &__bss_section_table_end) {

 ExeAddr = *SectionTableAddr ++;

 SectionLen = *SectionTableAddr ++;

 bss_init(ExeAddr, SectionLen);

 }

 // Reenable interrupts

 __asm volatile ("cpsie i");

 main();

 // main() shouldn't return, but if it does, we'll just enter an infinite loop

 while (1) {

;

 }

 }
