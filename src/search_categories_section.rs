use gtk::Frame;
use gtk::{prelude::{BoxExt, FrameExt, WidgetExt}, Box, CheckButton, DropDown, Label};

pub fn create_search_categories_section() -> Frame {
    let vbox = Box::new(gtk::Orientation::Vertical, 12);
    vbox.set_halign(gtk::Align::Start);
    vbox.set_valign(gtk::Align::Center);
    
    let check_box = Box::new(gtk::Orientation::Vertical, 0);
    let search_in_name = CheckButton::with_label("Name");
    let search_in_keywords = CheckButton::with_label("Keywords");
    let search_in_summary = CheckButton::with_label("Summary");
    let search_in_description = CheckButton::with_label("Description");
    let search_in_rpm_provides = CheckButton::with_label("RPM \"Provides\"");
    let search_in_rpm_requires = CheckButton::with_label("RPM \"Requires\"");
    let search_in_file_list = CheckButton::with_label("File list");

    check_box.append(&search_in_name);
    check_box.append(&search_in_keywords);
    check_box.append(&search_in_summary);
    check_box.append(&search_in_description);
    check_box.append(&search_in_rpm_provides);
    check_box.append(&search_in_rpm_requires);
    check_box.append(&search_in_file_list);

    vbox.append(&check_box);

    let search_mode_drop_down = DropDown::from_strings(&[
        "Contains",
        "Begins With",
        "Exact Match",
        "Use Wild Cards",
        "Use Regular Expression"
    ]);

    vbox.append(&search_mode_drop_down);

    let case_sensetive = CheckButton::with_label("Case Sensetive");
 
    vbox.append(&case_sensetive);

    let search_in_label = Label::new(None);
    search_in_label.set_markup("<b>Search in</b>");
    let frame = Frame::new(None);
    frame.set_label_widget(Some(&search_in_label));
    frame.set_margin_top(12);
    frame.set_child(Some(&vbox));
    frame
}