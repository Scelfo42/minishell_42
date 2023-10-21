<h1>Minishell</h1>
The aim of the project is to recreate a simple UNIX-like shell program in C, with advanced functionalities and command-line interface.
<h2>Overview</h2>
Minishell is a challenge to create a working shell, similar to bash. An opportunity to learn about process handling, low-level programming, file descriptor manipulation, command execution, system programming and terminal emulation. The shell have features like executing commands, handling environment variables, and implementing some built-in commands.
<h2>How To Use</h2>
<ol>
  <li>Clone the repository:</li>
  <pre><code>git clone</code></pre>
  <li>Move to the project's directory:</li>
  <pre><code>cd minishell</code></pre>
  <li>Compile the project with Makefile rule:</li>
  <pre><code>make</code></pre>
  <li>Enjoy our racoonshell🦝! Run the program with:</li>
    <pre><code>./minishell</code></pre>
  <h3>Features</h3>
<ul>
    <li>Display a prompt for new commands</li>
    <li>History</li>
    <li>Search and launch executables based on PATH variable or absolute/relative path</li>
    <li>Handle quotes and special characters</li>
    <li>Implement simple redirections and pipes</li>
    <li>Manage environment variables</li>
    <li>Handle ctrl-C, ctrl-D, and ctrl-\ inputs as bash does</li>
</ul>

<h3>Built-in commands:</h3>
<ul>
    <li>echo with option -n</li>
    <li>cd with only a relative or absolute path</li>
    <li>pwd with no options</li>
    <li>export with no options</li>
    <li>unset with no options</li>
    <li>env with no options or arguments</li>
    <li>exit with no options</li>
</ul>
</ol>
<h2>Info</h2>
For more information about this project, please read the subject file <a href="">here</a>.
<h2>Licence</h2>
See <a href="">License</a>.
