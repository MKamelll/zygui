use gio::prelude::{ApplicationExt, ApplicationExtManual};
use gtk::Application;

mod update_entry;
mod update_entry_table;
mod main_window;
mod updates_window;
mod zypper;
mod header_bar;

use main_window::main_window;

fn main() {
    let app = Application::builder().application_id("com.mkamelll.zygui").build();
    app.connect_activate(main_window);
    app.run(); 
}
