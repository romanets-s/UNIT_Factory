import lldb

def open_read(file):
    fd = open(file)
    if (fd):
        str = fd.read()
        fd.close()
        return (str)

def correct(debugger, command, result, internal_dict):
    trig = 0
    args = command.split(" ")
    if not len(args) == 3:
        exit()
    if debugger.GetSelectedTarget():                                        
        s = open_read("commandes")                                               
        list = s.split('\n')
        debugger.SetAsync(True)
        debugger.HandleCommand("breakpoint set --name main")
        debugger.HandleCommand("process launch")
        for line in list:
            debugger.HandleCommand(line)
            if line == "process continue":
                if trig < 3:
                    debugger.GetSelectedTarget().GetProcess().PutSTDIN(args[trig]+'\n')
                    trig += 1

def __lldb_init_module(debugger, internal_dict):

    debugger.HandleCommand('command script add -f correct.correct correct')
    print('The "correct" python command has been installed and is ready for use.')