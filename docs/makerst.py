
import glob
import subprocess
import os.path

for file in glob.glob('source/*.rst'):
	print 'Processing %s...' % file
	open(os.path.join('html', '%s.html' % os.path.basename(file)[:-4]), 'w').write(
			subprocess.Popen(['rst2html.py', '--stylesheet=rst.css', file],
				stdout = subprocess.PIPE).communicate()[0]
			)
