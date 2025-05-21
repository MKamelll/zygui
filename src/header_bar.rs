use gio::Menu;
use gtk::{prelude::{BoxExt}, Box, HeaderBar, MenuButton, PopoverMenu};

pub fn create_header_bar() -> HeaderBar {
    let file_menu = Menu::new();
    file_menu.append(Some("Import..."), None);
    file_menu.append(Some("Export..."), None);
    file_menu.append(Some("Exit -- Discard Packages"), None);
    file_menu.append(Some("Quit -- Save Packages"), None);

    let package_menu = Menu::new();
    package_menu.append(Some("Install"), None);
    package_menu.append(Some("Do Not Install"), None);
    package_menu.append(Some("Keep"), None);
    package_menu.append(Some("Delete"), None);
    package_menu.append(Some("Update"), None);
    package_menu.append(Some("Update Unconditionally"), None);
    package_menu.append(Some("Taboo -- Never Install"), None);

    let configurarion_menu = Menu::new();
    configurarion_menu.append(Some("Repositories..."), None);
    configurarion_menu.append(Some("Online Update..."), None);


    let dependencies_menu = Menu::new();
    dependencies_menu.append(Some("Check Now"), None);
    dependencies_menu.append(Some("AutoCheck"), None);
    dependencies_menu.append(Some("Install Recommended Packages"), None);

    
    let options_menu = Menu::new();
    options_menu.append(Some("Show -devel Packages"), None);
    options_menu.append(Some("Show -debuginfo/-debugsource Packages"), None);
    options_menu.append(Some("System Verification Mode"), None);
    options_menu.append(Some("Clean Up When Deleting Packages"), None);
    options_menu.append(Some("Allow Vendor Change"), None);

    let extras_menu = Menu::new();
    extras_menu.append(Some("Show Products"), None);
    extras_menu.append(Some("Show Package Changes"), None);
    extras_menu.append(Some("Show History"), None);
    extras_menu.append(Some("Install All Matching -debuginfo Packages"), None);
    extras_menu.append(Some("Install All Matching -debugsource Packages"), None);
    extras_menu.append(Some("Install All Matching Recommended Packages"), None);
    extras_menu.append(Some("Generate Dependency Resolver Test Case"), None);
    extras_menu.append(Some("Reset Ignored Dependency Conflicts"), None);

    let help_menu = Menu::new();
    help_menu.append(Some("Overview"), None);
    help_menu.append(Some("Symbols"), None);
    help_menu.append(Some("Keys"), None);

    let file_popover = PopoverMenu::from_model(Some(&file_menu));
    let file_button = MenuButton::builder()
    .popover(&file_popover)
    .build();
    file_button.set_label("File");

    let package_popover = PopoverMenu::from_model(Some(&package_menu));
    let package_button = MenuButton::builder()
    .popover(&package_popover)
    .build();
    package_button.set_label("Package");
    
    let configuration_popover = PopoverMenu::from_model(Some(&configurarion_menu));
    let configuration_button = MenuButton::builder()
    .popover(&configuration_popover)
    .build();
    configuration_button.set_label("Configuration");
    
    let dependencies_popover = PopoverMenu::from_model(Some(&dependencies_menu));
    let dependencies_button = MenuButton::builder()
    .popover(&dependencies_popover)
    .build();
    dependencies_button.set_label("Dependencies");
    
    let options_popover = PopoverMenu::from_model(Some(&options_menu));
    let options_button = MenuButton::builder()
    .popover(&options_popover)
    .build();
    options_button.set_label("Options"); 
    
    let extras_popover = PopoverMenu::from_model(Some(&extras_menu));
    let extras_button = MenuButton::builder()
    .popover(&extras_popover)
    .build();
    extras_button.set_label("Extras");
    
    let help_popover = PopoverMenu::from_model(Some(&help_menu));
    let help_button = MenuButton::builder()
    .popover(&help_popover)
    .build();
    help_button.set_label("Help");

    let menu_bar = Box::new(gtk::Orientation::Horizontal, 0);
    menu_bar.append(&file_button);
    menu_bar.append(&package_button);
    menu_bar.append(&configuration_button);
    menu_bar.append(&dependencies_button);
    menu_bar.append(&options_button);
    menu_bar.append(&extras_button);
    menu_bar.append(&help_button);

    let header = HeaderBar::builder()
    .show_title_buttons(true)
    .title_widget(&menu_bar)
    .build();

    header
}