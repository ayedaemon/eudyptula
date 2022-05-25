# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

  config.vm.box = "generic/centos7"
  # config.vm.network "private_network", ip: "192.168.33.10"
  config.vm.network "public_network", bridge: "wlan0"


  config.vm.synced_folder ".", "/vagrant_data"


  config.vm.provider "virtualbox" do |vb|
    # Display the VirtualBox GUI when booting the machine
    vb.gui = false

    # Customize the amount of memory on the VM:
    vb.memory = "1024"
  end

  config.vm.provision "shell", inline: <<-SHELL
    yum update -y
    yum install -y \
    kernel-devel \
    kernel-headers
    echo "TERM=linux" >> /etc/profile
  SHELL
end
