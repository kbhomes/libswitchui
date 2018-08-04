#pragma once

#include "common.h"
#include "element.h"
#include "scene.h"
#include "text.h"
#include "util.h"

#define SUI_MARGIN_SIDE 30
#define SUI_MARGIN_TOP 88
#define SUI_MARGIN_BOTTOM 73

#define SUI_MARGIN_TOOLBAR_SIDE 30
#define SUI_MARGIN_BETWEEN_TOOLBAR_ICON_TEXT  10
#define SUI_MARGIN_BETWEEN_TOOLBAR_BUTTONS    44

#define SUI_COLOR_BACKGROUND  0xffebebeb
#define SUI_COLOR_DARK        0xff2d2d2d
#define SUI_COLOR_LIGHT       0xff6d6d6d

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;

  PlFontData fontData;
  TTF_Font *fontSmall;
  TTF_Font *fontNormal;
  TTF_Font *fontHeading;
  TTF_Font *fontMassive;

  SDL_Texture *buttonATexture;
  SDL_Texture *buttonBTexture;
  int buttonAWidth, buttonAHeight;
  int buttonBWidth, buttonBHeight;
} SUI;

extern SUI ui;

enum SUIToolbarAction {
  SUIToolbarActionA, SUIToolbarActionB
};

int sui_init();
void sui_cleanup();

void sui_render_start();
void sui_render_end();

/*
 * Draw the actions on the bottom toolbar with the chosen icons and text
 *
 * @param count   number of actions that will be drawn
 * @param ...     list of pairs of action text and ToolbarAction
 *
 * @example `draw_bottom_toolbar(2, "OK", SUIToolbarActionA, "Back", SUIToolbarActionB);
 */
void sui_draw_bottom_toolbar(int count, ...);

/*
 * Draw the text on the top header
 *
 * @param text    text to display on the top of the header
 */
void sui_draw_top_header(const char *text);

SDL_Texture *sui_load_png(const void *data, size_t size);
SDL_Texture *sui_load_png_rescale(const void *data, size_t size, int width, int height);
void sui_draw_texture(SDL_Texture *texture, int x, int y, int w, int h);
void sui_draw_clipped_texture(SDL_Texture *texture, int x, int y, int w, int h, SUIRect *clip);

void sui_draw_clipped_box_bounds(SUIRect *bounds, SUIRect *clip, uint32_t color);
void sui_draw_clipped_box(int x, int y, int width, int height, SUIRect *clip, uint32_t color);

void sui_draw_clipped_rectangle_bounds(SUIRect *bounds, SUIRect *clip, uint32_t color);
void sui_draw_clipped_rectangle(int x, int y, int width, int height, SUIRect *clip, uint32_t color);
