#ifndef _ILI9325_H
#define _ILI9325_H

#include <DisplayCore.h>
#include <DSPI.h>

class ILI9325 : public DisplayCore {
    private:
        const uint8_t ILI932X_START_OSC          = 0x00;
        const uint8_t ILI932X_DRIV_OUT_CTRL      = 0x01;
        const uint8_t ILI932X_DRIV_WAV_CTRL      = 0x02;
        const uint8_t ILI932X_ENTRY_MOD          = 0x03;
        const uint8_t ILI932X_RESIZE_CTRL        = 0x04;
        const uint8_t ILI932X_DISP_CTRL1         = 0x07;
        const uint8_t ILI932X_DISP_CTRL2         = 0x08;
        const uint8_t ILI932X_DISP_CTRL3         = 0x09;
        const uint8_t ILI932X_DISP_CTRL4         = 0x0A;
        const uint8_t ILI932X_RGB_DISP_IF_CTRL1  = 0x0C;
        const uint8_t ILI932X_FRM_MARKER_POS     = 0x0D;
        const uint8_t ILI932X_RGB_DISP_IF_CTRL2  = 0x0F;
        const uint8_t ILI932X_POW_CTRL1          = 0x10;
        const uint8_t ILI932X_POW_CTRL2          = 0x11;
        const uint8_t ILI932X_POW_CTRL3          = 0x12;
        const uint8_t ILI932X_POW_CTRL4          = 0x13;
        const uint8_t ILI932X_GRAM_HOR_AD        = 0x20;
        const uint8_t ILI932X_GRAM_VER_AD        = 0x21;
        const uint8_t ILI932X_RW_GRAM            = 0x22;
        const uint8_t ILI932X_POW_CTRL7          = 0x29;
        const uint8_t ILI932X_FRM_RATE_COL_CTRL  = 0x2B;
        const uint8_t ILI932X_GAMMA_CTRL1        = 0x30;
        const uint8_t ILI932X_GAMMA_CTRL2        = 0x31;
        const uint8_t ILI932X_GAMMA_CTRL3        = 0x32;
        const uint8_t ILI932X_GAMMA_CTRL4        = 0x35;
        const uint8_t ILI932X_GAMMA_CTRL5        = 0x36;
        const uint8_t ILI932X_GAMMA_CTRL6        = 0x37;
        const uint8_t ILI932X_GAMMA_CTRL7        = 0x38;
        const uint8_t ILI932X_GAMMA_CTRL8        = 0x39;
        const uint8_t ILI932X_GAMMA_CTRL9        = 0x3C;
        const uint8_t ILI932X_GAMMA_CTRL10       = 0x3D;
        const uint8_t ILI932X_HOR_START_AD       = 0x50;
        const uint8_t ILI932X_HOR_END_AD         = 0x51;
        const uint8_t ILI932X_VER_START_AD       = 0x52;
        const uint8_t ILI932X_VER_END_AD         = 0x53;
        const uint8_t ILI932X_GATE_SCAN_CTRL1    = 0x60;
        const uint8_t ILI932X_GATE_SCAN_CTRL2    = 0x61;
        const uint8_t ILI932X_GATE_SCAN_CTRL3    = 0x6A;
        const uint8_t ILI932X_PART_IMG1_DISP_POS = 0x80;
        const uint8_t ILI932X_PART_IMG1_START_AD = 0x81;
        const uint8_t ILI932X_PART_IMG1_END_AD   = 0x82;
        const uint8_t ILI932X_PART_IMG2_DISP_POS = 0x83;
        const uint8_t ILI932X_PART_IMG2_START_AD = 0x84;
        const uint8_t ILI932X_PART_IMG2_END_AD   = 0x85;
        const uint8_t ILI932X_PANEL_IF_CTRL1     = 0x90;
        const uint8_t ILI932X_PANEL_IF_CTRL2     = 0x92;
        const uint8_t ILI932X_PANEL_IF_CTRL3     = 0x93;
        const uint8_t ILI932X_PANEL_IF_CTRL4     = 0x95;
        const uint8_t ILI932X_PANEL_IF_CTRL5     = 0x97;
        const uint8_t ILI932X_PANEL_IF_CTRL6     = 0x98;

        p32_ioport *_d0_port;
        p32_ioport *_d1_port;
        p32_ioport *_d2_port;
        p32_ioport *_d3_port;
        p32_ioport *_d4_port;
        p32_ioport *_d5_port;
        p32_ioport *_d6_port;
        p32_ioport *_d7_port;

        p32_ioport *_cs_port;
        p32_ioport *_wr_port;
        p32_ioport *_rd_port;
        p32_ioport *_rs_port;

        uint32_t _d0_mask;
        uint32_t _d1_mask;
        uint32_t _d2_mask;
        uint32_t _d3_mask;
        uint32_t _d4_mask;
        uint32_t _d5_mask;
        uint32_t _d6_mask;
        uint32_t _d7_mask;

        uint32_t _cs_mask;
        uint32_t _wr_mask;
        uint32_t _rd_mask;
        uint32_t _rs_mask;

        uint8_t _rs_pin;
        uint8_t _wr_pin;
        uint8_t _rd_pin;
        uint8_t _cs_pin;
        uint8_t _reset_pin;
        uint8_t _d0_pin;
        uint8_t _d1_pin;
        uint8_t _d2_pin;
        uint8_t _d3_pin;
        uint8_t _d4_pin;
        uint8_t _d5_pin;
        uint8_t _d6_pin;
        uint8_t _d7_pin;

        void regset(uint8_t r, uint16_t v) {
            command(r);
            data(v >> 8);
            data(v);
        }


	public:
        static const int Width      = 240;
        static const int Height     = 320;

		ILI9325(uint8_t rs, uint8_t wr, uint8_t rd, uint8_t cs, uint8_t reset,
                uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : 
            _rs_pin(rs), _wr_pin(wr), _rd_pin(rd), _cs_pin(cs), _reset_pin(reset),
            _d0_pin(d0), _d1_pin(d1), _d2_pin(d2), _d3_pin(d3),
            _d4_pin(d4), _d5_pin(d5), _d6_pin(d6), _d7_pin(d7) {}
        
		void setAddrWindow(int x0, int y0, int x1, int y1);
        void fillScreen(color_t color);
        void setPixel(int x, int y, color_t color);
        void drawVerticalLine(int x, int y, int h, color_t color);
        void drawHorizontalLine(int x, int y, int w, color_t color);
        void fillRectangle(int x, int y, int w, int h, color_t color);
        void setRotation(int r);
        void invertDisplay(boolean i);
        void displayOn() {} // Not implemented
        void displayOff() {} // Not implemented
        void openWindow(int, int, int, int);
        void windowData(color_t);
        void windowData(color_t *, int);
        void closeWindow();

        void initializeDevice();

        void data(uint8_t);
        void command(uint8_t);

};

#endif