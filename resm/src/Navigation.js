import React from 'react';
import "./style/Navigation.css";

const Navigation = () => {
    return (
        <>
            <div className="nav">
                <ul>
                    <li><a href="/">restauracje</a></li>
                    <li><a href="/">coś tam</a></li>
                    <li><a href="/">O Nas</a></li>
                </ul>
            </div>
        </>
    )
}

export default Navigation;