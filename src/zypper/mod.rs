use std::{process::Command, sync::mpsc, thread};
use crate::update_entry::UpdateEntry;

pub type UpdateParams = (String, String, String, String, String);

#[derive(Debug, Default)]
pub struct Zypper {}

impl Zypper {
    pub fn new() -> Self {
        Zypper::default()
    }

    pub fn list_of_updates(&self, sender: mpsc::Sender<UpdateParams>)
    {
        thread::spawn(move || {
            let ouput = Command::new("zypper")
            .arg("--quiet")
            .arg("list-updates")
            .output()
            .expect("Couldn't start the zypper command");
            
            let stdout = String::from_utf8_lossy(&ouput.stdout).to_string();
            let lines= stdout.lines().filter(|l| !l.is_empty());

            for line in lines.skip(2) {
                let package_line = line.split("|").collect::<String>();
                let package_params : Vec<&str> = package_line
                .split(" ")
                .skip(1)
                .filter(|p| { !p.is_empty() })
                .collect();
                sender.send((
                    package_params[0].to_string(),
                    package_params[1].to_string(), 
                    package_params[2].to_string(), 
                    package_params[3].to_string(),
                    package_params[4].to_string()
                )).expect(&format!("Failed to send '{:?}'", package_params[0].to_string()));
            }
        });
    }
}