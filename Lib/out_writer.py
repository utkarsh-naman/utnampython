import sys
import os
import datetime
from io import StringIO

def write_out(filename=""):
    script_name = os.path.basename(sys.argv[0]).replace(".py", "")
    if not filename:
        now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"{script_name}_{now}_output.txt"

    old_stdout = sys.stdout
    buffer = StringIO()
    sys.stdout = buffer

    try:
        exec(open(sys.argv[0]).read(), globals())

    except Exception as e:
        print(f"Error during execution: {e}")

    finally:
        sys.stdout = old_stdout  
    terminal_output = buffer.getvalue()

    with open(filename, "w", encoding="utf-8") as f:
        f.write(terminal_output)


