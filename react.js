class App extends React.Component {
    state = {}
    render() {
        return (
            <React.Fragment>
                <header>
                    <h1>Yummy</h1>
                </header>
                <main>
                    <h2>Restaurants</h2>
                    <div class="logo">
                        <img src="" alt=""></img>
                        <h3></h3>
                    </div>
                </main>
                <footer>
                    <section class="AboutUs">
                        <h2></h2>
                        <p></p>
                    </section>
                    <section class="contact">
                        <h2>Contact Us</h2>
                        <form action="">
                            <input type="text" placeholder="Your name" />
                            <input type="text" placeholder="Your email" />
                            <input type="text" placeholder="Your message" />
                            <button>Send message</button>
                        </form>
                    </section>
                </footer>
            </React.Fragment>
        )
    }
}

ReactDOM.render(<App />, document.getElementById("root"));