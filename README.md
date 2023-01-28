# Apache NuttX RTOS: NSH Task Demo

To build and run this NSH Demo App...

1.  Install the Build Prerequisites, skip the RISC-V Toolchain...

    ["Install Prerequisites"](https://lupyuen.github.io/articles/nuttx#install-prerequisites)

1.  Download the ARM64 Toolchain for
    AArch64 Bare-Metal Target `aarch64-none-elf`
    
    [Arm GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)

    (Skip the section for Beta Releases)

1.  Add the downloaded toolchain to the `PATH` Environment Variable...

    ```text
    gcc-arm-...-aarch64-none-elf/bin
    ```

    Check the ARM64 Toolchain...

    ```bash
    aarch64-none-elf-gcc -v
    ```

1.  Download QEMU Machine Emulator...

    ["Download QEMU"](https://lupyuen.github.io/articles/arm#download-qemu)

1.  Download NuttX...

    ```bash
    mkdir nuttx
    cd nuttx
    git clone https://github.com/apache/nuttx nuttx
    git clone https://github.com/apache/nuttx-apps apps
    cd nuttx
    ```

1.  Add `nshtask` to our NuttX Project...

    ```bash
    pushd ../apps/examples
    git submodule add https://github.com/lupyuen/nshtask
    popd
    ```

1.  Configure our NuttX Project...

    ```bash
    tools/configure.sh -l qemu-armv8a:nsh
    make menuconfig
    ```

1.  In "Application Configuration > Examples"

    Enable "NSH Task Demo"

1.  Optional: If we wish to start `nshtask` when NuttX boots...

    In "RTOS Features > Tasks and Scheduling"

    Set "Application entry point" to `nshtask_main`

    Set "Application entry name" to `nshtask_main`

1.  Save the configuration and exit `menuconfig`

1.  Build NuttX...

    ```bash
    make
    ```

1.  Run NuttX with QEMU...

    ```bash
    qemu-system-aarch64 -cpu cortex-a53 -nographic \
      -machine virt,virtualization=on,gic-version=3 \
      -net none -chardev stdio,id=con,mux=on -serial chardev:con \
      -mon chardev=con,mode=readline -kernel ./nuttx
    ```

1.  At the NSH Prompt, enter...

    ```bash
    nshtask
    ```

    When we're done, press Ctrl-C to quit QEMU.

# Incorrect Response from ChatGPT

> "How to create a NuttX Task for NSH Shell"

> "To create a NuttX task for the NSH shell, you will need to do the following steps:"

> "In your NuttX application's main file, include the necessary headers for task creation and the NSH shell:"

```c
#include <nuttx/sched.h>
#include <nuttx/nsh.h>
```

> "In the main function of your application, create a new task using the `task_create()` function, passing in the necessary parameters such as the task's entry point, its name, and its stack size."

> "In the entry point function for the task, call the `nsh_main()` function to start the NSH shell."

> "Finally, start the task using the `task_start()` function, passing in the task's ID as a parameter."

> "Here is a sample code:"

https://github.com/lupyuen/nshtask/blob/c9d4f0b6fa60eb7cb5d0795e6670e012deefab61/nshtask.c#L2-L28
