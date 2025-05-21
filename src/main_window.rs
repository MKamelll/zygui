use gtk::{prelude::{GtkWindowExt, WidgetExt}, Application, ApplicationWindow};
use crate::header_bar::create_header_bar;

pub fn main_window(app: &Application) {
    let window = ApplicationWindow::builder()
    .application(app)
    .title("Zygui")
    .default_width(640)
    .default_height(480)
    .build();

    let header = create_header_bar();

    window.set_titlebar(Some(&header));
    window.set_visible(true);
}