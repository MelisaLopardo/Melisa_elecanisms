path = ['C:\Program Files (x86)\Microchip\xc16\v1.24\bin']
env = Environment(PIC = '24FJ128GB206', 
                  CC = 'xc16-gcc', 
                  PROGSUFFIX = '.cof', 
                  CFLAGS = '-g -omf=coff -x c -mcpu=$PIC', 
                  LINKFLAGS = '-omf=coff -mcpu=$PIC -Wl,--script="app_p24FJ128GB206.gld"', 
                  CPPPATH = '../lib')
env.PrependENVPath('PATH', 'xc16-gcc.exe')
bin2hex = Builder(action = 'xc16-bin2hex $SOURCE -omf=coff',
                  suffix = 'hex', 
                  src_suffix = 'cof')
env.Append(BUILDERS = {'Hex' : bin2hex})
list = Builder(action = 'xc16-objdump -S -D $SOURCE > $TARGET', 
               suffix = 'lst', 
               src_suffix = 'cof')
env.Append(BUILDERS = {'List' : list})

env.Program('blink', ['blink.c',
                      '../lib/timer.c',
                      '../lib/ui.c'])
env.Hex('blink')
env.List('blink')

