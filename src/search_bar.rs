use gtk::{prelude::{BoxExt}, Box, Button, SearchEntry};

pub fn crate_search_bar_with_button() -> Box {
    let h_box = Box::new(gtk::Orientation::Horizontal, 4);
    let search_button = Button::with_label("Search");
    let search_bar = SearchEntry::new();
    h_box.append(&search_bar);
    h_box.append(&search_button);
    h_box
}