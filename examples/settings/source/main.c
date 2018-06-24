#include <switch.h>
#include <switchui.h>

SUISidebar sidebar;

void init() {
  sui_sidebar_init(
        &sidebar,
        20,
        "Support/Health & Safety",
        SUI_SIDEBAR_DIVIDER,
        "Airplane Mode",
        "Screen Brightness",
        "Screen Lock",
        SUI_SIDEBAR_DIVIDER,
        "Parental Controls",
        "Internet",
        "Data Management",
        "Users",
        "Mii",
        "amiibo",
        SUI_SIDEBAR_DIVIDER,
        "Themes",
        "Notifications",
        "Sleep Mode",
        SUI_SIDEBAR_DIVIDER,
        "Controllers and Sensors",
        "TV Settings",
        "System"
  );
}

int update(SUIInput *input) {
  sui_sidebar_update(&sidebar, input);

  // Exit if B or + is clicked
  if (input->buttons.down & KEY_B || input->buttons.down & KEY_PLUS) {
    return -1;
  }

  return 0;
}

void render() {
  // Begin drawing
  sui_render_start();

  // Draw the settings sidebar
  sui_sidebar_render(&sidebar);

  // Draw the top and bottom toolbars
  sui_draw_top_header("System Settings");
  sui_draw_bottom_toolbar(2, "OK", SUIToolbarActionA, "Back", SUIToolbarActionB);

  // Display
  sui_render_end();
}

void cleanup() {
  sui_sidebar_cleanup(&sidebar);
}

int main(int argc, char **argv) {
  socketInitializeDefault();
  nxlinkStdio();

  // Initialize the UI
  sui_init();
  init();

  // Update and render loop
  while (1) {
    SUIInput *input = sui_input_poll(CONTROLLER_P1_AUTO);

    if (update(input) < 0)
      break;

    render();
  }

  // Cleanup the UI
  cleanup();
  sui_cleanup();
}
