use gio::Menu;
use gtk::{prelude::{BoxExt, GtkWindowExt, WidgetExt}, Application, ApplicationWindow, Box, Label, MenuButton, Popover, PopoverMenu, Stack, StackSwitcher};
use crate::header_bar::create_header_bar;

pub fn create_stack() -> Stack {
    let stack = Stack::new();
    stack.set_transition_type(gtk::StackTransitionType::SlideLeftRight);

    stack.add_titled(&Label::new(Some("this is search")), Some("search"), "Search");
    stack.add_titled(&Label::new(Some("this is installation summary")),
    Some("installation summary"), "Installation Summary");
    stack.add_titled(&Label::new(Some("this is patterns")), Some("patterns"), "Patterns");
    stack
}

fn create_switcher(stack: &Stack) -> StackSwitcher {
    let switcher = StackSwitcher::new();
    switcher.set_stack(Some(stack));
    switcher.set_hexpand(true);
    switcher
}

fn create_view_drop_down_menu() -> MenuButton {
    let view_drop_down = Menu::new();
    view_drop_down.append(Some("Patterns"), None);
    view_drop_down.append(Some("Package Classification"), None);
    view_drop_down.append(Some("Languages"), None);
    view_drop_down.append(Some("Repositories"), None);
    view_drop_down.append(Some("Services"), None);
    view_drop_down.append(Some("Search"), None);
    view_drop_down.append(Some("Installation Summary"), None);

    let popover_menu = PopoverMenu::from_model(Some(&view_drop_down));
    let view_drop_down_button = MenuButton::builder().popover(&popover_menu).label("View ").build();
    view_drop_down_button.set_hexpand(true);

    view_drop_down_button
}

pub fn create_hbox_of_switcher_and_view_button() -> Box {
    let container = Box::new(gtk::Orientation::Horizontal, 0);
    container.set_hexpand(true);
    container.append(&create_view_drop_down_menu());
    container.append(&create_switcher(&create_stack()));
    container
}