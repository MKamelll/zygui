use std::{cell::RefCell, vec};

use glib::{subclass::{object::ObjectImpl, types::ObjectSubclass}, value::ToValue, ParamSpec, ParamSpecBuilderExt, ParamSpecString, ParamSpecStringBuilder};

#[derive(Default, Debug)]
pub struct UpdateEntry {
    pub repo: RefCell<String>,
    pub name: RefCell<String>,
    pub pre_version: RefCell<String>,
    pub post_version: RefCell<String>,
    pub arch: RefCell<String>
}

#[glib::object_subclass]
impl ObjectSubclass for UpdateEntry {
    const NAME: &'static str = "UpdateEntry";
    type Type = super::UpdateEntry;
    type ParentType = glib::Object;
}

impl ObjectImpl for UpdateEntry {
    fn properties() -> &'static [glib::ParamSpec] {
        static PROPS: once_cell::sync::Lazy<Vec<ParamSpec>> = once_cell::sync::Lazy::new(|| {
            vec![
                ParamSpecString::builder("repo").nick("Repo").blurb("The repo of the package").build(),
                ParamSpecString::builder("name").nick("Name").blurb("The name of the package").build(),
                ParamSpecString::builder("pre-version").nick("PreVersion").blurb("The pre version of the package").build(),
                ParamSpecString::builder("post-version").nick("PostVersion").blurb("The post version of the package").build(),
                ParamSpecString::builder("arch").nick("Arch").blurb("The arch of the package").build(),
            ]
        });

        &PROPS
    }

    fn property(&self, _id: usize, _pspec: &ParamSpec) -> glib::Value {
        match _pspec.name() {
            "repo" => self.repo.borrow().to_value(),
            "name" => self.name.borrow().to_value(),
            "pre-version" => self.pre_version.borrow().to_value(),
            "post-version" => self.post_version.borrow().to_value(),
            "arch" => self.arch.borrow().to_value(),
            _ => unimplemented!()
        }
    }

    fn set_property(&self, _id: usize, _value: &glib::Value, _pspec: &ParamSpec) {
        match _pspec.name() {
            "repo" => {
                let name = _value.get().unwrap();
                *self.repo.borrow_mut() = name;
            }

            "name" => {
                let name = _value.get().unwrap();
                *self.name.borrow_mut() = name;
            }

            "pre-version" => {
                let name = _value.get().unwrap();
                *self.pre_version.borrow_mut() = name;
            }

            "post-version" => {
                let name = _value.get().unwrap();
                *self.post_version.borrow_mut() = name;
            }

            "arch" => {
                let name = _value.get().unwrap();
                *self.arch.borrow_mut() = name;
            }

            _ => unimplemented!()
        }
    }
}