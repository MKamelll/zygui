use gio::Menu;
use gtk::{prelude::{BoxExt, GtkWindowExt, WidgetExt}, Application, ApplicationWindow, Box, Label, MenuButton, Popover, PopoverMenu, Stack, StackSwitcher};
use crate::header_bar::create_header_bar;
use crate::stack_switcher::{create_hbox_of_switcher_and_view_button, create_stack};

pub fn main_window(app: &Application) {
    let window = ApplicationWindow::builder()
    .application(app)
    .title("Zygui")
    .default_width(640)
    .default_height(480)
    .build();

    let layout = Box::new(gtk::Orientation::Vertical, 0);
    layout.set_hexpand(true);
    layout.set_vexpand(true);
    layout.append(&create_hbox_of_switcher_and_view_button());
    layout.append(&create_stack());

    let header = create_header_bar();
    window.set_titlebar(Some(&header));

    window.set_child(Some(&layout));
    window.set_visible(true);
}