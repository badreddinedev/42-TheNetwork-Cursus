# 42Born2beroot-1337
## Introduction :
You will begin by setting up your inaugural virtual machine using VirtualBox. Alternatively, if VirtualBox is unavailable, you may utilize UTM for this purpose. Ensure to follow precise instructions throughout the process. By the project's conclusion, you will gain the knowledge to independently establish your operating system, adhering to stringent guidelines and regulations.

## What-is-a-Virtual-Machine?
A virtual machine is a software application capable of simulating the installation of an entire Operating System within its environment. By doing so, it tricks the OS into believing it is running on an actual physical computer. The virtual machine creates virtual devices that mirror the behavior of real physical devices, such as CPU, memory, network interface, and storage. This emulation is made possible as the virtual machine is hosted on a physical device, which provides the necessary hardware resources.
The software responsible for creating and managing virtual machines is called a hypervisor. Its main role is to isolate the resources allocated to each virtual machine from the underlying hardware of the host system. In this way, the VMs can utilize these resources effectively and independently.
The physical devices that supply the hardware resources are known as host machines or hosts, while the virtual machines assigned to a host are referred to as guests or guest machines. The hypervisor efficiently allocates a portion of the host machine's CPU, storage, etc., distributing them among the various virtual machines.
Since each virtual machine operates in isolation, multiple VMs can coexist on the same host without interfering with one another. This allows us to run different operating systems on our machine simultaneously. For each virtual machine, we have the flexibility to use a distinct operating system distribution. Despite being virtual, each OS behaves as if it were running on a dedicated physical device, thereby delivering an experience similar to using an OS on an actual machine.

## How-do-Virtual-Machines-work?
Virtualization enables us to create multiple virtual environments, effectively sharing a single physical system. The hypervisor, as the virtualization software, takes charge of managing the hardware system and isolates the physical resources from the virtual environments. This separation ensures that the resources are efficiently allocated based on the needs of the virtual machines, moving resources from the host to the guests as required.
- Here are some of the advantages that arise from utilizing virtual machines:
--- Diverse Operating Systems: Virtual machines empower us to run various guest machines on our computer, each equipped with a different operating system. This versatility allows multiple OSes to coexist on the same machine.

--- Safe Testing Environment: Virtual machines provide a secure testing ground for experimenting with potentially unstable programs. This way, we can assess if these applications will negatively impact the overall system without risking the stability of the host environment.

--- Optimal Resource Utilization: Through virtualization, shared resources can be more effectively utilized. The hypervisor dynamically manages the distribution of resources among virtual machines, ensuring efficient usage of CPU, memory, network, and storage.

--- Cost Reduction: The adoption of virtual machines can lead to cost savings by minimizing the need for physical hardware. Fewer physical servers are required since multiple virtual machines can run on a single physical host, reducing the expenses associated with maintaining separate physical architectures.

--- Ease of Implementation: Virtual machines offer straightforward mechanisms for cloning a virtual instance and deploying it on another physical device. This ease of duplication simplifies the process of replicating virtual environments across various systems.
By harnessing the power of virtual machines, we can unlock these advantages, enhancing flexibility, efficiency, and cost-effectiveness in managing our computing infrastructure.

## What-is-LVM?
To fully grasp the advantages of LVM (Logical Volume Manager) and how it facilitates flexible partition management, it's essential to understand the key concepts and components of LVM:
--- Physical Volumes (PVs): These are the actual storage devices (hard drives, solid-state drives, etc.) that LVM utilizes. Before LVM can manage a device, it must be initialized as a Physical Volume.

--- Volume Group (VG): A Volume Group is a collection of one or more Physical Volumes grouped together. It serves as a pool of storage from which Logical Volumes can be created.

--- Logical Volumes (LVs): Logical Volumes are created within a Volume Group. They act as virtual partitions and represent the space available for file systems to be created on top of them. Unlike traditional partitions, Logical Volumes can be resized and moved easily.

--- Extents: The storage space in a Volume Group is divided into fixed-size units called extents. These extents are usually a few megabytes in size.

With these fundamental concepts, we can better understand the advantages of LVM:
--- Flexibility in Partition Management: LVM provides unparalleled flexibility when it comes to managing storage. Since Logical Volumes are not tied to specific physical locations, they can be expanded, shrunk, or moved without the limitations of traditional partitions. This enables efficient space allocation and utilization across the entire storage pool.

--- Dynamic Resizing of Logical Volumes: Unlike conventional partitions that require complex and often risky operations to resize, LVM allows for on-the-fly resizing of Logical Volumes. Administrators can easily extend or shrink a Logical Volume as needed without unmounting or impacting running services.

--- Aggregating Storage from Multiple Devices: LVM can pool storage from various Physical Volumes (disks), enabling the creation of large and scalable Volume Groups that aggregate the capacities of multiple disks into a single storage pool.

--- Migration and Redundancy: LVM supports moving Logical Volumes between different Physical Volumes, facilitating data migration and system maintenance. Additionally, LVM can provide a degree of redundancy through techniques like mirroring (RAID) and striping, enhancing data protection.

In summary, LVM acts as a flexible abstraction layer that liberates us from the constraints of traditional partitioning schemes. It empowers system administrators to allocate, resize, and manage storage resources dynamically, making it a powerful tool for efficient storage utilization and system maintenance.

## What-is-AppArmor?
AppArmor provides Mandatory Access Control (MAC) security, allowing administrators to restrict processes' actions. For example, if an application tries to access the camera without permission, AppArmor blocks it to prevent system damage. Profiles in AppArmor control process restrictions and can work in enforce-mode (strict) or complain-mode (logs complaints). This offers a simple yet effective way to enhance system security and protect sensitive resources.

## What-is-the-difference-between-Apt-and-Aptitute?
In Debian-based operating system distributions, the default package manager is dpkg. This tool facilitates the installation, removal, and management of programs on the system. However, when installing programs, they often come with a list of dependencies that must be satisfied for the main program to function correctly. While one option is manually installing these dependencies, the Advanced Package Tool (APT), which works in conjunction with dpkg, offers a more efficient solution by automatically handling dependencies during program installation. This means that with a single command, we can install a useful program along with all its required dependencies.
APT works with various back-ends and front-ends to make its services accessible. One such front-end is apt-get, which enables us to install and remove packages. Additionally, there are other tools like apt-cache that allow efficient program management. In this context, apt-get and apt-cache are utilized by APT to streamline the process of installing .deb programs without the hassle of manually managing dependencies.
For users who prefer a graphical interface, aptitude is available. Aptitude provides a more sophisticated approach to handling dependencies, allowing users to choose between different dependency options when installing a program. This enhances user control and flexibility during the installation process.
In summary, APT in conjunction with dpkg simplifies the installation of programs and their dependencies, making it a convenient package management system for Debian-based operating systems. Users can opt for command-line tools like apt-get and apt-cache or utilize the graphical interface provided by aptitude for a more interactive experience with dependency management.

## How-to-use-SSH?
SSH (Secure Shell) is a secure remote administration protocol that allows users to control servers over the Internet. It encrypts data during communication, ensuring secure authentication and protection against eavesdropping. SSH serves as a safer alternative to Telnet and permits Linux and macOS users to access their servers remotely via the terminal. Its encrypted communication and remote terminal access make it a vital tool for secure server management.

The command used to connect to a server with ssh is:

$ ssh {username}@{IP_host} -p {port}

Exactly! SSH utilizes three different encryption techniques to ensure secure communication:
--- Symmetric Encryption: This method employs a single secret key for both encryption and decryption of a message, used by both the client and the host. The same key is applied for both directions of communication. However, the security of symmetric encryption relies on keeping the secret key private, as anyone with knowledge of the key can access the transmitted message.

--- Asymmetric Encryption: In contrast to symmetric encryption, asymmetric encryption utilizes two separate keys for encryption and decryption. These keys form a public-private key pair. The public key is shared openly and used for encryption, while the corresponding private key is kept secret and used for decryption. Messages encrypted with the public key can only be decrypted with the matching private key, providing enhanced security.

--- Hashing: SSH also employs hashing, which is a different form of cryptography. Hash functions generate fixed-size hash values from input data, and unlike encryption, these hashes cannot be decrypted to obtain the original data. Instead, SSH uses hashes to verify data integrity. When a client has the correct input, it can create a cryptographic hash, and SSH compares this hash with the received hash to check if the data remains intact and unaltered during transmission.
By incorporating these encryption techniques, SSH ensures that data exchanged between the client and the host remains confidential, authenticated, and protected against unauthorized modifications or tampering.

## How-to-implement-UFW-with-SSH
UFW (Uncomplicated Firewall) is a user-friendly software application that simplifies the management of iptables, which is a powerful firewall tool in Linux. While iptables offers robust security features, it can be complex and challenging to work with directly.
UFW provides an intuitive interface that allows system administrators to modify the firewall rules (netfilter) in a straightforward manner, without compromising security. With UFW installed, administrators can easily configure the firewall to allow or block incoming and outgoing connections on specific ports.
For example, when using SSH, administrators can use UFW to specify which ports they want to allow SSH connections on and close other ports, improving security by reducing the attack surface. This streamlined approach to managing the firewall makes it more accessible and less error-prone for administrators, enhancing the overall security of the system.
By leveraging UFW, Linux users can effectively configure firewall rules to suit their specific needs, ensuring that the system remains protected while maintaining ease of use. UFW is particularly valuable for simplifying the process of securing SSH connections and enhancing communication security between devices.

## What-is-cron-and-what-is-wall?
Indeed, as system administrators, two crucial commands that greatly aid in managing a server are cron and wall.

--- Cron: Cron is a Linux task manager that allows scheduling and automating repetitive tasks at specified times or intervals. It is an essential tool for system administrators to execute commands, scripts, or programs automatically. By configuring cron jobs, administrators can schedule tasks to run daily, weekly, monthly, or at custom intervals. For example, if a server needs to be restarted every day at 4:00 am for maintenance, the administrator can create a cron job to handle this task without manual intervention. cron ensures that critical tasks are performed consistently and timely, improving system efficiency and reducing the need for manual intervention.

--- Wall: The wall command in Linux is utilized by the root user to send messages or alerts to all users who are currently connected to the server. It serves as a communication tool for system administrators to broadcast important announcements to all logged-in users simultaneously. For example, if there is a significant server change or maintenance that might cause users to be disconnected, the root user can use wall to inform them in advance. This helps in minimizing disruptions, providing users with essential information, and maintaining smooth communication between administrators and users.
Both cron and wall are invaluable tools that enhance the efficiency of system administration tasks and improve communication within the server environment. They contribute to the overall stability, organization, and user experience on the server, making them essential utilities for any Linux system administrator.
