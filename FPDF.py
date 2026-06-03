# To install fpdf on your MacBook, open Terminal and run:
# pip3 install fpdf
# To check installation and version:
# python3 -m pip show fpdf
# or in code:
# import fpdf; print(fpdf.__version__)

import fpdf;
print(fpdf.__version__)
from fpdf import FPDF

# Define the PDF class
class PDF(FPDF):
    def header(self):
        self.set_font("Arial", "B", 14)
        self.cell(0, 10, "Qualcomm Embedded/Linux Firmware Interview Prep Guide", ln=True, align="C")
        self.ln(5)

    def chapter_title(self, title):
        self.set_font("Arial", "B", 12)
        self.set_fill_color(200, 220, 255)
        self.cell(0, 10, title, ln=True, fill=True)
        self.ln(2)

    def chapter_body(self, body):
        self.set_font("Arial", "", 10)
        self.multi_cell(0, 8, body)
        self.ln()

# Create PDF
pdf = PDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()

# Content Sections
sections = [
    ("C Programming & Memory", 
     "1. const vs #define with examples\n"
     "2. volatile keyword use-case\n"
     "3. const + volatile together (ADC register example)\n"
     "4. Undefined behavior in expressions like printf(\"%d %d %d\", a, a++, ++a);\n"
     "5. C Memory Layout: Text, Data, BSS, Heap, Stack\n"),

    ("Embedded Systems & MCU Memory", 
     "1. Types of MCU memory: Flash, SRAM, EEPROM\n"
     "2. Memory mapping and register-based access\n"
     "3. Example of memory section placement using __attribute__((section(\".my_sec\")))\n"),

    ("RTOS Concepts", 
     "1. Semaphore vs Mutex: ownership, recursion\n"
     "2. FreeRTOS task states, priorities, vTaskDelay\n"
     "3. Critical section with taskENTER_CRITICAL/taskEXIT_CRITICAL\n"),

    ("Linux & Embedded Linux", 
     "1. Commands: free -m, /proc/meminfo, top\n"
     "2. Device Tree purpose with example\n"
     "3. Tools: GDB, Valgrind, strace, dmesg\n"),

    ("ARM Architecture", 
     "1. ARM Modes: User, FIQ, IRQ, Supervisor, Abort, Undefined, System\n"
     "2. Registers: PC, SP, LR, CPSR, SPSR\n"),

    ("Communication Protocols", 
     "1. I2C vs SPI: wires, speed, addressing\n"
     "2. RS-485 vs UART: differential, multi-drop\n"
     "3. RS-485 slave selection using protocol (MODBUS)\n"),

    ("Debugging & Real-Time Scenarios", 
     "1. Stack overflow detection with FreeRTOS hook\n"
     "2. UART hang issue debug approach\n"),

    ("Resume-Based Behavioral Q&A", 
     "1. Kernel boot optimization - Thermo Fisher\n"
     "2. SPI wakeup bug - Si91x\n"
     "3. Automation & Doxygen - Silicon Labs\n"
     "4. DO178C compliance - Airbus\n"
     "5. Legacy code integration - OPC UA SDK\n")
]

# Add sections to PDF
for title, content in sections:
    pdf.chapter_title(title)
    pdf.chapter_body(content)

# Save PDF
output_path = "./Qualcomm_Embedded_Linux_Interview_Prep_Veerendra.pdf"
pdf.output(output_path)

output_path