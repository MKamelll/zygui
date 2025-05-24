use gio::Menu;
use gtk::{prelude::{BoxExt, GtkWindowExt, WidgetExt}, Application, ApplicationWindow, Box, Button, Label, MenuButton, Popover, PopoverMenu, SearchEntry, Stack, StackSwitcher};
use crate::{header_bar::create_header_bar, search_bar};
use crate::stack_switcher::{create_hbox_of_switcher_and_view_button, create_stack};
use crate::search_bar::crate_search_bar_with_button;

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
    let header = create_header_bar();
    window.set_titlebar(Some(&header));
    
    let hbox_switcher_and_view_button = create_hbox_of_switcher_and_view_button();
    let stack = create_stack();
    layout.append(&hbox_switcher_and_view_button);
    layout.append(&stack);

    let search_bar = crate_search_bar_with_button();  
    layout.append(&search_bar);

    window.set_child(Some(&layout));
    window.set_visible(true);
}